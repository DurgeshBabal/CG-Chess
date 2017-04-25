// header for game play class
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

class GamePlay
{
        int PieceId;
        int SideColor;
        int xmin, ymin;
        int xmax, ymax;
        int xmid, ymid;

    public:
        // GamePlay();
        //
        // ~GamePlay() = default;
        // GamePlay(const GamePlay& other) = default;
        // GamePlay(GamePlay&& other) = default;
        // GamePlay& operator=(const GamePlay& other) = default;
        // GamePlay& operator=(GamePlay&& other) = default;

        int GetPieceId();
        int GetSideColor();
        int GetCellOrdinates();
        int GetMidPoints();
};
