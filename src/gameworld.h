#ifndef GAME_WORLD_H
#define GAME_WORLD_H 1
class GameWorld {
public:
    GameWorld (int h, int w)
        :m_iH(h), m_iW(w) {}

    const int height() const { return m_iH; }
    const int width() const { return m_iW; }

private:
    int m_iH, m_iW;

};
#endif
