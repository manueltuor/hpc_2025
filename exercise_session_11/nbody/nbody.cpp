#include <random>
#include <vector>
#include <cmath>
using std::vector;

struct particles {
    vector<float> x, y, z;    // position
    vector<float> vx, vy, vz; // velocity
    vector<float> ax, ay, az; // acceleration
};

void ic(particles &plist, int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    plist.x.resize(n);
    plist.y.resize(n);
    plist.z.resize(n);
    plist.vx.resize(n, 0.0f);
    plist.vy.resize(n, 0.0f);
    plist.vz.resize(n, 0.0f);
    plist.ax.resize(n, 0.0f);
    plist.ay.resize(n, 0.0f);
    plist.az.resize(n, 0.0f);

    for (int i = 0; i < n; ++i) {
        plist.x[i]  = dis(gen);
        plist.y[i]  = dis(gen);
        plist.z[i]  = dis(gen);
    }
}

void forces(particles &plist) {
    int n = plist.x.size();

    for (int i = 0; i < n; ++i) {
        float ax = 0.0f, ay = 0.0f, az = 0.0f;

        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            float dx = plist.x[j] - plist.x[i];
            float dy = plist.y[j] - plist.y[i];
            float dz = plist.z[j] - plist.z[i];

            float r = sqrtf(dx*dx + dy*dy + dz*dz);
            float ir3 = 1.0f / (r * r * r);

            ax += dx * ir3;
            ay += dy * ir3;
            az += dz * ir3;
        }

        plist.ax[i] = ax;
        plist.ay[i] = ay;
        plist.az[i] = az;
    }
}

int main(int argc, char *argv[]) {
    int N = 50000;

    particles plist;
    ic(plist, N);
    forces(plist);

    return 0;
}
