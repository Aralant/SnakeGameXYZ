#pragma once
#include "Text.h"

class TextBlock
{
public:

    enum class Alignment
    {
        Start,
        Center,
        End,
        None
    };

    TextBlock();

    TextBlock(
        const sf::Vector2f& start,
        float verticalSpacing,
        Alignment hOrigin = Alignment::Center,
        Alignment vOrigin = Alignment::Center
    );

    void AddText(Text& text);
    void AddText(
        const std::string& content,
        const sf::Font& font,
        const sf::Color& color = sf::Color::White,
        unsigned int characterSize = 30
    );
    const Text& GetText(const int index) const;
    void SetColor(const int index, const sf::Color& color);
    void AlignTexts();
    void SetVerticalSpacing(const int spacing);
    void SetStartPosition(const sf::Vector2f position);
    void SetAlignmentProperties(const Alignment blockHorizontal, const Alignment blockVertical, const Text::Alignment textHorizontal);
    void Draw(sf::RenderWindow& window) const;
    void Clear();

private:
    std::vector<Text> _texts; 
    sf::Vector2f _start; 
    float _verticalSpacing; 
    sf::FloatRect _boundingRect; 
    Alignment _hOrigin;
    Alignment _vOrigin;
    Text::Alignment _textAlignment; 

    void UpdateBoundingRect();
    void UpdateTextPositions();
    sf::Vector2f GetOriginAdjustment() const;
};
