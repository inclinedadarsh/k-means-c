#ifndef TEST_DATASET
#define TEST_DATASET

#include "../include/matrix.h"

Matrix create_test_dataset() {
  Matrix dataset = create_matrix(20, 2);

  dataset.data[0][0] = 1.0;
  dataset.data[0][1] = 2.0;

  dataset.data[1][0] = 1.5;
  dataset.data[1][1] = 1.8;

  dataset.data[2][0] = 5.0;
  dataset.data[2][1] = 8.0;

  dataset.data[3][0] = 8.0;
  dataset.data[3][1] = 8.0;

  dataset.data[4][0] = 1.0;
  dataset.data[4][1] = 0.6;

  dataset.data[5][0] = 9.0;
  dataset.data[5][1] = 11.0;

  dataset.data[6][0] = 8.0;
  dataset.data[6][1] = 2.0;

  dataset.data[7][0] = 10.0;
  dataset.data[7][1] = 2.0;

  dataset.data[8][0] = 9.0;
  dataset.data[8][1] = 3.0;

  dataset.data[9][0] = 3.0;
  dataset.data[9][1] = 1.5;

  dataset.data[10][0] = 2.5;
  dataset.data[10][1] = 7.0;

  dataset.data[11][0] = 3.5;
  dataset.data[11][1] = 8.0;

  dataset.data[12][0] = 4.0;
  dataset.data[12][1] = 7.5;

  dataset.data[13][0] = 3.0;
  dataset.data[13][1] = 6.0;

  dataset.data[14][0] = 3.5;
  dataset.data[14][1] = 1.0;

  dataset.data[15][0] = 5.5;
  dataset.data[15][1] = 4.5;

  dataset.data[16][0] = 6.0;
  dataset.data[16][1] = 4.0;

  dataset.data[17][0] = 4.5;
  dataset.data[17][1] = 6.5;

  dataset.data[18][0] = 5.0;
  dataset.data[18][1] = 5.5;

  dataset.data[19][0] = 6.5;
  dataset.data[19][1] = 3.5;

  return dataset;
}

#endif // !TEST_DATASET
