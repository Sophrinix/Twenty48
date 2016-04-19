#pragma once
/**
 * This file includes a prototype representing the ui of the game
 */
#include <array>
#include <memory>

namespace twentyfortyeight {
namespace testing {

class ActivityController;

using GameBoard = std::array<std::array<uint16_t, 4>, 4>;

/// A singleton object that represents the gameui
class GameUI {
  uint16_t score_text_ = 0;
  GameBoard board_;
  uint16_t hi_score_text_ = 0;
  uint16_t times_played_ = 0;

 public:
  GameUI(const GameUI&) = delete;
  GameUI(GameUI&&) = delete;
  GameUI& operator=(const GameUI&) = delete;
  GameUI& operator=(GameUI&&) = delete;

 protected:
  GameUI();
  ~GameUI();
  static GameUI& Instance();
  friend class ActivityController;
};

}  // namespace testing
}  // namespace twentyfortyeight