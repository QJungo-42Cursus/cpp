#include <fstream>
#include <iostream>

static void open_file(std::ifstream &file, std::string filename) {
  file.open(filename, std::ios::in);
  if (!file.good()) {
    std::cerr << "File " << filename << " does not exist" << std::endl;
    exit(1);
  }
  if (!file.is_open()) {
    std::cerr << "Error opening file " << filename << std::endl;
    exit(1);
  }
}

static void create_file(std::ofstream &new_file, std::string filename) {
  new_file.open(filename, std::ios::out);
  if (!new_file.good()) {
    std::cerr << "Error creating file " << filename << std::endl;
    exit(1);
  }
  if (!new_file.is_open()) {
    std::cerr << "Error opening file " << filename << std::endl;
    exit(1);
  }
}

static void sed(std::ifstream &file, std::ofstream &new_file,
                std::string string1, std::string string2) {
  std::string content_file;
  content_file.assign((std::istreambuf_iterator<char>(file)),
                      (std::istreambuf_iterator<char>()));
  int pos = 0;
  while ((pos = content_file.find(string1, pos)) != (int)std::string::npos) {
    content_file.erase(pos, string1.length());
    content_file.insert(pos, string2);
  }
  new_file << content_file;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>"
              << std::endl;
    exit(1);
  }

  /// File names
  std::string filename = argv[1];
  std::string filename_copy = filename + std::string(".replace");

  /// Open/Create files
  std::ifstream file;
  std::ofstream file_copy;
  open_file(file, filename);
  create_file(file_copy, filename_copy);

  /// Sed
  sed(file, file_copy, argv[2], argv[3]);

  /// Close files
  file.close();
  file_copy.close();
  return 0;
}
