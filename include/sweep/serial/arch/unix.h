/*The MIT License (MIT)
 *
 * Copyright (c) 2016, Scanse LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#if !defined(_WIN32)

#ifndef UNIX_H
#define UNIX_H

#include <iostream>
#include <string>
#include <termios.h>
#include <sweep/serial/v8stdint.h>

class SerialArch {
public:
  SerialArch(const std::string &port, uint32_t baudrate, uint32_t timeout);

  virtual ~SerialArch();

  void open();

  void close();

  bool isOpen();

  void flush();

  size_t write(const uint8_t *data, size_t length);

  size_t read(uint8_t *buf, size_t size);

  bool waitReadable();

private:
  speed_t getbaud(uint32_t baudrate);

  std::string port_;
  uint32_t baudrate_;
  uint32_t timeout;
  int fd_;
  bool is_open_;
};

#endif // UNIX_H

#endif // !defined(_WIN32)
