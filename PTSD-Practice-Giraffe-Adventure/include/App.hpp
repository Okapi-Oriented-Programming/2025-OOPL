#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include <memory>
#include "Character.hpp"
#include "Util/Text.hpp"
#include "PhaseResourceManger.hpp"
#include "AnimatedCharacter.hpp"
#include <vector>


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

    void UpdateBall(float deltaTime);

    enum class Phase {
        CHANGE_CHARACTER_IMAGE,
        ABLE_TO_MOVE,
        COLLIDE_DETECTION,
        BEE_ANIMATION,
        OPEN_THE_DOORS,
        COUNTDOWN,
    };


private:
    void ValidTask();



    State m_CurrentState = State::START;
    Phase m_Phase = Phase::CHANGE_CHARACTER_IMAGE;

    Util::Renderer m_Root;

    std::shared_ptr<Character> m_Giraffe;
    std::shared_ptr<Character> m_Chest;
    std::vector<std::shared_ptr<Character>> m_Doors;
    std::vector<std::string> ballFrames;

    std::shared_ptr<AnimatedCharacter> m_Bee;
    std::shared_ptr<AnimatedCharacter> m_Ball;

    std::shared_ptr<PhaseResourceManger> m_PRM;


    glm::vec2 m_ChestPosition;
    float m_ChestWidth;
    float m_ChestHeight;
    bool m_ChestVisible = true;

    float m_GiraffeWidth;
    float m_GiraffeHeight;

    std::vector<glm::vec2> m_DoorPositions;
    float m_DoorWidth;
    float m_DoorHeight;

    std::vector<bool> m_DoorVisible;

    bool m_EnterDown = false;

    bool hasExecuted = false;


};

#endif
