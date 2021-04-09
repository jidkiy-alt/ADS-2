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
  int leftS = 0, count = 0, mid = 0, i = 0;
  int rightS = len-1;
  bool midCenter = true, rightPos = false;
  while (leftS <= rightS && arr[i] <= value/2) {
    if (midCenter)
      mid = (leftS+rightS)/2;
    if (arr[i] + arr[mid] == value || !midCenter) {
      if (arr[mid+1] + arr[i] == value && !rightPos) {
        midCenter = false;
        mid++;
      } else if (arr[mid-1] + arr[i] == value) {
        rightPos = true; midCenter = false;
        mid--;
        if (i != mid && i < mid)
          count++;
      } else {
        rightPos = false; midCenter = true;
        if (i != mid)
          count++;
        leftS = 0; rightS = len-1;
        i++;
      }
    }
    if (arr[i] + arr[mid] > value)
      rightS = mid-1;
    if (arr[i] + arr[mid] < value)
      leftS = mid+1;
    if (leftS > rightS) {
      leftS = 0; rightS = len-1;
      i++;
    }
  }
  return count;
}
