# Theorie sur les cast

cast implicit : cast que le compilateur fait sans qu'on le precise (eg: int a = 5; float b = a;) ->conversion
conversion (implicit ou explicit): change l'encodage en bit d'un valeur pour qu'elle aie dans un autre type de variable avec la (presque) meme valeur
demotion de type: faire une conversion vers une variable avec moins de memoire -> moins de precision (float vers int) -> doit ce faire explicitemnt
promotion: l'inverse (gain de precision)
flag gcc pour prevenir des pertes d'infos

---

Conversion identitaire, reinterpretation: garder les bits dans le meme ordre 
```c
float a = 5.0f;
void *ap = &a;
int *c = ap; //va faire de la medre
```

--- 

Type qualifier : const et volatil

# Nouveau cast C++

upcast et down cast -> cast d'une class mere vers sa fille et inversement 

--- 

static cast -> equivalent du cast classique de c

```c++
int		a = 42;
double	b = a;
int		d = static_cast<int>(b); // demotion explicit
```

dans le contexte de up/down cast -> detect si les class ne sont pas de la meme famille
  et nous empeche de compiler

---

dynamic cast -> le seul qui a lui au runtime (tout les autres se font a la compilation)
! peut donc creer des erreurs !
ne peut marcher qu'avec au moins une method virtuelle dans l'arbre de class

ne s'utilise que pour des down cast et verifie si c'est possible de le faire

```c++
class Mother {}
class Child : Mother {}

Mother *m = new Mother();
Child *c = dynamic_cast<Child *>(m); // renvoie NULL si le cast est impossible
Child &c = dynamic_cast<Child &>(*m); // throw une erreur si le cast est impossible std::bad_cast
```

---

reinterpreter cast -> reinterprete sans aucune verification

```c++
int		a = 42;
void	*a_p = &a;
int		d = reinterpreter_cast<int *>(a_p);
```

---

const cast
...

```c++
int			a = 42;
const int *	a_p = &a;
int *		d = const_cast<int *>(b);
```

---

cast specifier

grace a ces declaration d'operateur, on peut assigner implicitement les valeurs
dans les types qu'on a choisi (ici float et int)

```c++
class Flex {

public:
	// constructeur
	// blabla

	operator float()	{ return this->_v; }
	operator int()		{ return static_cast<int>(this->_v); }

private:
	float _v;

}
```

---

explicit

force l'utitilisateur de la fonction (seulement pour les constructeur??)
a cast (s'il y a lieu de cast) explicitement
```c++
class YY {
public:
				YY();
				YY( ... ); // osef
	explicit	YY( ... ); // cast obligatoir

```

