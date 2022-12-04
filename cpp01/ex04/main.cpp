#include <fstream>
#include <iostream>

void open_file(std::ifstream &file, char *filename) {
  file.open(filename, std::ios::in);
  if (!file.good()) {
    std::cout << "File " << filename << " does not exist" << std::endl;
    exit(1);
  }
  if (!file.is_open()) {
    std::cout << "Error opening file " << filename << std::endl;
    exit(1);
  }
}

void create_file(std::ofstream &new_file, std::string filename) {
  new_file.open(filename, std::ios::out);
  if (!new_file.good()) {
    std::cout << "Error creating file " << filename << std::endl;
    exit(1);
  }
  if (!new_file.is_open()) {
    std::cout << "Error opening file " << filename << std::endl;
    exit(1);
  }
}

void sed(std::ifstream &file, std::ofstream &new_file, std::string string1,
         std::string string2) {
  std::string content_file;
  content_file.assign((std::istreambuf_iterator<char>(file)),
                      (std::istreambuf_iterator<char>()));
  int pos = 0;
  while ((pos = content_file.find(string1, pos)) != std::string::npos) {
    content_file.erase(pos, string1.length());
    content_file.insert(pos, string2);
  }
  new_file << content_file;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cout << "Usage: " << argv[0] << " <filename> <string1> <string2>"
              << std::endl;
    exit(1);
  }

  std::ifstream file;
  std::ofstream file_copy;
  std::string file_name = argv[1];
  std::string file_name_copy = argv[1] + std::string(".replace");

  open_file(file, argv[1]);
  create_file(file_copy, file_name_copy.c_str());

  sed(file, file_copy, argv[2], argv[3]);

  file.close();
  file_copy.close();
  return 0;
}
