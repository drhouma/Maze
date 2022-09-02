/**
 * @file    core.h
 * @authors Savin A.     <telvina<at>student.21-school.ru>
 * @authors Degtyarev A. <sreanna<at>student.21-school.ru>
 * @date    22/08/22
 */

#ifndef CORE_H
#define CORE_H

namespace s21 {

/**
 * @enum  Mode
 * @brief Defines in which mode render scene need work
 */

enum class Mode {
    NONE = 0,
    MAZE,
    CAVE
};

auto RandomBool() -> bool;
auto PercentRandomBool(int percent) -> bool;

} // namespace s21

#endif // CORE_H
