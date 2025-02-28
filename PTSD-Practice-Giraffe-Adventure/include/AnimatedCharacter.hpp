#ifndef ANIMATED_CHARACTER_HPP
#define ANIMATED_CHARACTER_HPP

#include <vector>
#include <string>

#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"


class AnimatedCharacter : public Util::GameObject {

public:

    explicit AnimatedCharacter(const std::vector<std::string>& AnimationPaths,bool play,bool looping );

    void Update(float deltaTime);

    [[nodiscard]] bool IsLooping() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetLooping();
    }

    [[nodiscard]] bool IsPlaying() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetState() == Util::Animation::State::PLAY;
    }


    [[nodiscard]] bool IfAnimationEnds() const;

    void SetDrawable(std::shared_ptr<Util::Image> newImage) {
        m_Drawable = newImage;  // 更新圖像
    }

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
};

#endif //ANIMATED_CHARACTER_HPP
