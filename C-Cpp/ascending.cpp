#include<bits/stdc++.h>
int main()
{
  int i,j,k,n;

  printf("How many values");
  scanf("%d",&n);
  char a[n];
  char b[n];
  printf("give the input");
  for(i=0;i<n;i++)
  {scanf("%d",&a[i]);
  }
  for(i,j=0;i<n,j<n;i++,j++)
  {if(a[i]>a[i+1]){b[j]=a[i+1];
  b[j+1]=a[i];

  }
  else if(a[i]<a[i+1]){b[j]=a[i];
  b[j+1]=a[i+1];
  }
  else{continue;
  }
  }
  for(k=0;k<n;k++){printf("%d\n",b[k]);
  }
}
