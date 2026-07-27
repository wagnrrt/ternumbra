#include "raylib.h"
#include <string>

namespace Assets {

const char *GetPath(const std::string &file) {
  static std::string path;
  path = std::string(GetApplicationDirectory()) + "resources/" + file;

  return path.c_str();
}

} // namespace Assets
