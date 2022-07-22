// SPDX-License-Identifier: MIT
#pragma once

#include <string>
#include <algorithm>
#include <sstream>

namespace tinyusdz {

inline bool startsWith(const std::string &str, const std::string &t) {
  return (str.size() >= t.size()) &&
         std::equal(std::begin(t), std::end(t), std::begin(str));
}

inline bool endsWith(const std::string &str, const std::string &suffix) {
  return (str.size() >= suffix.size()) &&
         (str.find(suffix, str.size() - suffix.size()) != std::string::npos);
}

inline bool contains(const std::string &str, char c) {
  return str.find(c) == std::string::npos;
}

// Remove the beginning and the ending delimiter(s) from input string
// e.g. "mystring" -> mystring
// no error for an input string which does not contain `delim` in both side.
inline std::string unwrap(const std::string &str, const std::string &delim = "\"") {
  size_t n = delim.size();

  if (str.size() < n) {
    return str;
  }

  std::string s = str;

  if (s.substr(0, n) == delim) {
    s.erase(0, n);
  }
  
  if (s.substr(s.size() - n) == delim) {
    s.erase(s.size() - n);
  }

  return s;
}

inline std::string wrap(const std::string &s, const std::string &delim) {
  return delim + s + delim; 
}

// Python like join  ", ".join(v)
template<typename It>
inline std::string join(const std::string& sep, const It& v)
{
  std::ostringstream oss;
  if (!v.empty()) {
    typename It::const_iterator it = v.begin();
    oss << *it++;
    for (typename It::const_iterator e = v.end(); it != e; ++it)
      oss << sep << *it;
  }
  return oss.str();
}

#if 0
template<typename It>
inline std::string join(const std::string& sep, It& v)
{
  std::ostringstream oss;
  if (!v.empty()) {
    typename It::iterator it = v.begin();
    oss << *it++;
    for (typename It::iterator e = v.end(); it != e; ++it)
      oss << sep << *it;
  }
  return oss.str();
}
#endif


} // namespace tinyusdz
