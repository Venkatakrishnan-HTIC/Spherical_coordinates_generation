#define _USE_MATH_DEFINES
#include<random>
#include<cmath>
#include<chrono>


int main(int argc, char *argv[]) {
    // Set up random number generators
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator (seed);
    std::uniform_real_distribution<double> uniform01(0.0, 1.0);

    // generate N random numbers
    int N = 100;

    // the correct way
    FILE * correct;
    FILE * incorrect;
    FILE * delta;
    FILE * norm;
    correct = fopen("correct.csv", "w");
    incorrect = fopen("incorrect.csv", "w");
    delta = fopen("delta.csv", "w");
    norm = fopen("norm.csv", "w");
    fprintf(correct, "Theta,Phi,x,y,z\n");
    fprintf(incorrect, "x_n,y_n,z_n\n");
    fprintf(delta,"delta_x,delta_y,delta_z\n");
    fprintf(norm,"l2norm\n");
    for (int i = 0; i < N; i++) {
        // incorrect way
        double theta = 2 * M_PI * uniform01(generator);
        double phi = acos(1 - 2 * uniform01(generator));
        double x = 100 * sin(phi) * cos(theta);
        double x_n = x + ((double) rand() / (RAND_MAX));
        double delta_x = x_n-x;
        double y = 100 * sin(phi) * sin(theta);
        double y_n = y  + ((double) rand() / (RAND_MAX));
        double delta_y = y_n-y;
        double z = 100 * cos(phi);
        double z_n = z  + ((double) rand() / (RAND_MAX));
        double delta_z = z_n-z;
        double l2norm = sqrt(pow(delta_x,2) + pow(delta_y,2) + pow(delta_z,2));
        fprintf(correct, "%f,%f,%f,%f,%f\n", theta, phi, x, y, z);
        fprintf(incorrect, "%f,%f,%f\n", x_n, y_n, z_n);
        fprintf(delta,"%f,%f,%f\n", delta_x,delta_y,delta_z);
        fprintf(norm, "%f\n",l2norm);
    }
    fclose(correct);
    fclose(incorrect);
    fclose(delta);
    fclose(norm);
}