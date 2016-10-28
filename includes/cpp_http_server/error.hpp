#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>

namespace cpp_http_server {

class error : public std::runtime_error {
public:
  //! ctor & dtor
  error(const std::string& what, const std::string& file, std::uint32_t line);
  ~error(void) = default;

  //! copy ctor & assignment operator
  error(const error&) = default;
  error& operator=(const error&) = default;

public:
  //! get location of the error
  const std::string& get_file(void) const;
  std::uint32_t get_line(void) const;

private:
  //! location of the error
  std::string m_file;
  std::uint32_t m_line;
};

} //! cpp_http_server

//! macro for convenience
#define __CPP_HTTP_SERVER_THROW(what) throw cpp_http_server::error(what, __FILE__, __LINE__);
