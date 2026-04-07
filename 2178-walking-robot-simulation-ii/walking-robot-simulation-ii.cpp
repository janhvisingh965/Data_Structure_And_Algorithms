class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 0; // 0=East, 1=North, 2=West, 3=South
    int perimeter;

    vector<string> dirs = {"East", "North", "West", "South"};
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h) - 4;
    }

    void step(int num) {
        num %= perimeter;

        // Special case ONLY when at origin
        if (num == 0 && x == 0 && y == 0) {
            dir = 3; // South
            return;
        }

        while (num > 0) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // If out of bounds → turn
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4;
            } else {
                x = nx;
                y = ny;
                num--;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return dirs[dir];
    }
};