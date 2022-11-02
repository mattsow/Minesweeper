#ifndef MinesweeperBoard_h
#define MinesweeperBoard_h

enum GameMode{DEBUG_MODE, EASY, NORMAL, HARD};
enum GameState{RUNNING, FINISHED_WIN, FINISHED_LOSS};

struct Field{
    bool hasMine;
    bool isRevealed;
    bool hasFlag;
};

class MinesweeperBoard{
    Field board[100][100];
    int width;
    int height;
    GameMode mode;
    int actionCount;
    bool play;
    
public:
    MinesweeperBoard(int width, int height, GameMode mode);
    int getBoardWidth() const;
    int sizeWidth() const;
    int getBoardHeight() const;
    int sizeHeight() const;
    int getMineCount() const;
    int getMinesLeft() const;
    int getFieldsLeft() const;
    int countMines(int row, int col) const;
    float setDifficultyLevel() const;
    bool isRevealed(int row, int col) const;
    void revealField(int row, int col);
    int fieldSize() const;
    bool hasFlag(int row, int col) const;
    void toggleFlag(int row, int col);
    bool hasMine(int row, int col) const;
    void generateMine();
    void moveMine(int row, int col);
    GameState gameState() const;
    GameMode gameMode() const;
    bool playAgain();
    char getFieldInfo(int row, int col) const;
    void debug_display() const;
};

#endif
