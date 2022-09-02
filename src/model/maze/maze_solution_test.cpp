#include <gtest/gtest.h>

#include "maze.h"

TEST(Solution_base, test1) {
  s21::Maze maze;
  maze.Load("./data/Maze/test/maze_4_4_0.txt");
  std::vector<std::pair<int, int>> correctRes;
  correctRes.emplace_back(2, 0);
  correctRes.emplace_back(3, 0);
  correctRes.emplace_back(3, 1);
  correctRes.emplace_back(2, 1);
  correctRes.emplace_back(1, 1);
  correctRes.emplace_back(1, 0);
  correctRes.emplace_back(0, 0);
  std::vector<std::pair<int, int>> res = maze.FindPath({0, 0}, {2, 0});
  for (int i = 0; i < correctRes.size(); i++) {
    ASSERT_EQ(correctRes[i], res[i]);
  }
}
TEST(Solution_base, test2) {
  s21::Maze maze;
  maze.Load("./data/Maze/test/maze_4_4_0.txt");
  std::vector<std::pair<int, int>> correctRes;
  correctRes.emplace_back(3, 3);
  correctRes.emplace_back(2, 3);
  correctRes.emplace_back(2, 2);
  correctRes.emplace_back(2, 1);
  correctRes.emplace_back(1, 1);
  correctRes.emplace_back(1, 0);
  correctRes.emplace_back(0, 0);
  std::vector<std::pair<int, int>> res = maze.FindPath({0, 0}, {3, 3});
  for (int i = 0; i < correctRes.size(); i++) {
    ASSERT_EQ(correctRes[i], res[i]);
  }
}

TEST(Solution_base, test3) {
  s21::Maze maze;
  maze.Load("./data/Maze/test/maze_4_4_0.txt");
  std::vector<std::pair<int, int>> correctRes;
  correctRes.emplace_back(0, 3);
  correctRes.emplace_back(0, 2);
  correctRes.emplace_back(1, 2);
  correctRes.emplace_back(2, 2);
  correctRes.emplace_back(2, 1);
  correctRes.emplace_back(1, 1);
  correctRes.emplace_back(1, 0);
  correctRes.emplace_back(0, 0);
  std::vector<std::pair<int, int>> res = maze.FindPath({0, 0}, {0, 3});
  for (int i = 0; i < correctRes.size(); i++) {
    ASSERT_EQ(correctRes[i], res[i]);
  }
}

TEST(Solution_hard, test1) {
  s21::Maze maze;
  maze.Load("./data/Maze/test/maze_10_10_1.txt");
  std::vector<std::pair<int, int>> correctRes;
  correctRes.emplace_back(1, 0);
  correctRes.emplace_back(2, 0);
  correctRes.emplace_back(3, 0);
  correctRes.emplace_back(4, 0);
  correctRes.emplace_back(5, 0);
  correctRes.emplace_back(6, 0);
  correctRes.emplace_back(7, 0);
  correctRes.emplace_back(8, 0);
  correctRes.emplace_back(8, 1);
  correctRes.emplace_back(8, 2);
  correctRes.emplace_back(9, 2);
  correctRes.emplace_back(9, 3);
  correctRes.emplace_back(9, 4);
  correctRes.emplace_back(9, 5);
  correctRes.emplace_back(9, 6);
  correctRes.emplace_back(8, 6);
  correctRes.emplace_back(7, 6);
  correctRes.emplace_back(7, 7);
  correctRes.emplace_back(6, 7);
  correctRes.emplace_back(5, 7);
  correctRes.emplace_back(4, 7);
  correctRes.emplace_back(4, 6);
  correctRes.emplace_back(3, 6);
  correctRes.emplace_back(2, 6);
  correctRes.emplace_back(2, 5);
  correctRes.emplace_back(2, 4);
  correctRes.emplace_back(1, 4);
  correctRes.emplace_back(0, 4);
  correctRes.emplace_back(0, 3);
  correctRes.emplace_back(0, 2);
  correctRes.emplace_back(1, 2);
  correctRes.emplace_back(2, 2);
  correctRes.emplace_back(2, 1);
  correctRes.emplace_back(1, 1);
  correctRes.emplace_back(0, 1);
  correctRes.emplace_back(0, 0);
  std::vector<std::pair<int, int>> res = maze.FindPath({0, 0}, {1, 0});
  for (int i = 0; i < correctRes.size(); i++) {
    ASSERT_EQ(correctRes[i], res[i]);
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
