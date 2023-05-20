int min(int a, int b)
{
  if (a < b)
  {
    return a;
  }
  else
  {
    return b;
  }
}
void main()
{
  int amt;
  printf("enter the amount you want\n");
  scanf("%d", &amt);
  int den[4] = {1, 5, 6, 8};
  int ans[4][amt + 1];
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j <= amt; j++)
    {
      ans[i][j] = 0;
    }
  }
  for (int i = 0; i <= amt; i++)
  {
    ans[0][i] = i;
  }
  for (int i = 1; i < 4; i++)
  {
    for (int j = 0; j <= amt; j++)
    {
      if (j < den[i])
      {
        ans[i][j] = ans[i - 1][j];
      }
      else
      {
        ans[i][j] = min(ans[i][j - den[i]] + 1, ans[i - 1][j]);
      }
    }
  }

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j <= amt; j++)
    {
      printf("%d\t", ans[i][j]);
    }
    printf("\n");
  }
}

