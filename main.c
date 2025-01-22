#include "datasets/test-dataset.h"
#include "include/matrix.h"
#include <math.h>
#include <stdio.h>

int main(void)
{
  Matrix dataset = create_test_dataset();
  int datasize = dataset.rows;

  float c1[] = {dataset.data[0][0], dataset.data[0][1]};
  float c2[] = {dataset.data[1][0], dataset.data[1][1]};
  float c3[] = {dataset.data[2][0], dataset.data[2][1]};

  int clusters[datasize];
  int epoch = 10;
  float epsilon = 0.001; // Convergence threshold

  for (int e = 0; e < epoch; e++)
  {
    for (int i = 0; i < datasize; i++)
    {
      float dis_1 = sqrt(pow(dataset.data[i][0] - c1[0], 2) +
                         pow(dataset.data[i][1] - c1[1], 2));
      float dis_2 = sqrt(pow(dataset.data[i][0] - c2[0], 2) +
                         pow(dataset.data[i][1] - c2[1], 2));
      float dis_3 = sqrt(pow(dataset.data[i][0] - c3[0], 2) +
                         pow(dataset.data[i][1] - c3[1], 2));

      int min = 1;
      float min_dis = dis_1;

      if (dis_2 < min_dis)
      {
        min_dis = dis_2;
        min = 2;
      }

      if (dis_3 < min_dis)
      {
        min_dis = dis_3;
        min = 3;
      }

      clusters[i] = min;
    }

    float c1_mean[2] = {0, 0};
    int c1_count = 0;
    float c2_mean[2] = {0, 0};
    int c2_count = 0;
    float c3_mean[2] = {0, 0};
    int c3_count = 0;

    for (int i = 0; i < datasize; i++)
    {
      if (clusters[i] == 1)
      {
        c1_mean[0] += dataset.data[i][0];
        c1_mean[1] += dataset.data[i][1];
        c1_count++;
      }
      else if (clusters[i] == 2)
      {
        c2_mean[0] += dataset.data[i][0];
        c2_mean[1] += dataset.data[i][1];
        c2_count++;
      }
      else
      {
        c3_mean[0] += dataset.data[i][0];
        c3_mean[1] += dataset.data[i][1];
        c3_count++;
      }
    }

    c1_mean[0] /= c1_count;
    c1_mean[1] /= c1_count;
    c2_mean[0] /= c2_count;
    c2_mean[1] /= c2_count;
    c3_mean[0] /= c3_count;
    c3_mean[1] /= c3_count;

    // After mean calculations, update centroids
    float change = 0;
    change += fabs(c1[0] - c1_mean[0]) + fabs(c1[1] - c1_mean[1]);
    change += fabs(c2[0] - c2_mean[0]) + fabs(c2[1] - c2_mean[1]);
    change += fabs(c3[0] - c3_mean[0]) + fabs(c3[1] - c3_mean[1]);

    c1[0] = c1_mean[0];
    c1[1] = c1_mean[1];
    c2[0] = c2_mean[0];
    c2[1] = c2_mean[1];
    c3[0] = c3_mean[0];
    c3[1] = c3_mean[1];

    if (change < epsilon)
    {
      printf("Converged at epoch %d\n", e + 1);
      break;
    }
  }

  printf("\nCluster 1: ");
  for (int i = 0; i < datasize; i++)
  {
    if (clusters[i] == 1)
    {
      // printf("P%d(%f, %f), ", i, dataset.data[i][0], dataset.data[i][1]);
      printf("P%d, ", i);
    }
  }

  printf("\nCluster 2: ");
  for (int i = 0; i < datasize; i++)
  {
    if (clusters[i] == 2)
    {
      // printf("P%d(%f, %f), ", i, dataset.data[i][0], dataset.data[i][1]);
      printf("P%d, ", i);
    }
  }

  printf("\nCluster 3: ");
  for (int i = 0; i < datasize; i++)
  {
    if (clusters[i] == 3)
    {
      // printf("P%d(%f, %f), ", i, dataset.data[i][0], dataset.data[i][1]);
      printf("P%d, ", i);
    }
  }

  free_matrix(&dataset); // Clean up
  return 0;
}
