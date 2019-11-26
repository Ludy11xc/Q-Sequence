/**
 * Short program to calculate nth number in the Q Sequence
 *
 */


#include <iostream>
#include <ios>

//int steps = 100;
//std::cout.setf(std::ios::unitbuf);

class QSeq {
public:
  int Q(int n);
  int maxR();

  QSeq(int n) {
    std::cout << "Finding #" << n << " Q number..." << std::endl;
    done = 0;
    nums = new int[n];
    for (int i = 1; i < n+1; i++) {
      int k = q(i);
      nums[i-1] = k;
      done = i;
    }
    /*
    for (int i = 0; i < n; i++) {
      std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;
    */
  }

private:
  int q(int n);
  int done;
  int* nums;
};


int main(int argc, char*argv[]) {

  std::cout << std::unitbuf; //enable automatic flushing

  int steps = atoi(argv[1]);

  std::cout << "Steps: " << steps << std::endl;

  QSeq *qs = new QSeq(steps);
  std::cout << qs->Q(steps) << std::endl;

  int in = qs->maxR();
}

int QSeq::maxR() {
  float max = 0.0;
  int maxIndex = 0;
  for (int i = 3; i < done + 1; i++) {
    float rat = (float)nums[i-1] / (float)(i+1);
    //std::cout << rat << std::endl;
    if (rat > max) {
      //std::cout << "Rat > max" << std::endl;
      max = rat;
      maxIndex = i;
    }
  }
  std::cout << "Max ratio: " << max << "; Index: " << maxIndex << std::endl;
  return maxIndex;
}

int QSeq::Q(int n) {
  return q(n);
}

int QSeq::q(int n) {
  if (n == 1 || n == 2) {
    return 1;
  }
  if (n <= done) {
    return nums[n-1];
  }
  return q(n-q(n-1))+q(n-q(n-2));
}
