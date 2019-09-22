#include <stdio.h>
#include <iostream>
#include <map>
#include <stdlib.h>


int main(int argc, char **argv)
{
  FILE *fp = fopen("data", "r");

  using namespace std;
  
  if(fp == NULL)
    printf("file couldn't be loaded");

  std::map<int, int> seen;
  map<int,int>::iterator comp;
  
  char buf[100];
  int temp;
  
  
  while(!feof(fp))
    {
      //fgets(buf, 20, fp);
      fscanf(fp, "%s", buf);
      temp = atoi(buf);

      if(temp == 0)
	continue;
      
      comp = seen.find(temp);
      if(comp != seen.end())
	++seen[temp];
      else
	seen.emplace(temp, 1);
      buf[0] = 0;
    }


  map<int,int>::iterator it;

  for(it = seen.begin(); it != seen.end(); it++)
    {
      cout<< it->first << "\t" << it->second <<endl;
    }
  
  /* c++ map use
  seen.emplace(10, 2);

  map<int,int>::iterator comp = seen.find(10);

  if(comp != seen.end())
    seen[10]++;

  map<int, int>::iterator it;

  for(it = seen.begin(); it != seen.end(); it++)
    cout << it->first << "\t" << it->second << endl;
  */
  return 0;
}
