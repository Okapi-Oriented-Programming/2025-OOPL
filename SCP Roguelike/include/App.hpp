#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include "Player.hpp"
#include "Hand.hpp"
class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();

private:
    State m_CurrentState = State::START;
    std::shared_ptr<Player> m_Player = std::make_shared<Player>();
    std::shared_ptr<Hand> m_Hand = std::make_shared<Hand>(m_Player);
    Util::Renderer m_Root;
};

#endif
