#ifndef GAMEDATA_HPP_
#define GAMEDATA_HPP_

#include <bitset>

enum class Input { Up1, Down1, Up2, Down2, ESC };  // Game possible inputs
enum class State {
  Menu,
  Playing,
  ScoreP1,
  ScoreP2,
  Player1Win,
  Player2Win
};  // Game possible states

struct GameData {
  State m_state{State::Playing};
  std::bitset<5> m_input;  // [Up1, Down1, Up2, Down2, ESC, Menu]
};

#endif