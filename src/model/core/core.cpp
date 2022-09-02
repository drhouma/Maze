/**
 * @file    core.cpp
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    22/08/22
 */

#include <random>

namespace s21 {

auto RandomBool() -> bool {
  std::random_device rd;
  std::default_random_engine engine{rd()};
  std::uniform_int_distribution<int> dist{0, 1};
  return static_cast<bool>(dist(engine));
}

auto PercentRandomBool(const int percent) -> bool {
  std::random_device rd;
  std::default_random_engine engine{rd()};
  std::uniform_int_distribution<int> dist{0, 100};
  return dist(engine) < percent;
}

}  // namespace s21
