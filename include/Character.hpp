#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"

class Character : public Util::GameObject {
public:
    explicit Character(const std::string& ImagePath);

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    // TODO: Implement the collision detection
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const {
        // 獲取當前角色和其他角色的邊界
        auto thisPosition = this->GetPosition();
        auto otherPosition = other->GetPosition();

        // 假設角色的大小為 width 和 height
        const float width = 50.0f;  // 角色的寬度
        const float height = 50.0f; // 角色的高度

        // 計算當前角色的邊界
        float thisLeft = thisPosition.x;
        float thisRight = thisPosition.x + width;
        float thisTop = thisPosition.y;
        float thisBottom = thisPosition.y + height;

        // 計算其他角色的邊界
        float otherLeft = otherPosition.x;
        float otherRight = otherPosition.x + width;
        float otherTop = otherPosition.y;
        float otherBottom = otherPosition.y + height;

        // 檢查是否相交
        return (thisLeft < otherRight && thisRight > otherLeft &&
                thisTop < otherBottom && thisBottom > otherTop);
    }





    // TODO: Add and implement more methods and properties as needed to finish Giraffe Adventure.

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};


#endif //CHARACTER_HPP
