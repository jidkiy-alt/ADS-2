// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = len-1; i > -1; i--) {
    for (int j = 0; j != i; ++j) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int leftS = 0, count = 0, mid = 0;
  int rightS = len-1;
  for (int i = 0; i < len/2; i++) {
    while (leftS <= rightS) {
      mid = (leftS + rightS) / 2;
      if (arr[i] + arr[mid] == value) {
        count++;
        leftS = mid-1;
      }
      if (arr[i] + arr[mid] > value)
        rightS = mid-1;
      if (arr[i] + arr[mid] < value)
        leftS = mid+1;
    }
    mid = (leftS + rightS) / 2;
    leftS = 0; rightS = len-1;
  }
  return count;
}
