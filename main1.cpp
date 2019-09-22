#include <iostream>
#include "node.cpp"
#include <set>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <unistd.h>

static node *root;


//main algorithm for a balanced tree creation. The array should be sorted
void recurse(std::vector<int> arr, node *locRoot, int start, int end)
{
  int mid = (start+end) / 2;
  locRoot->data = arr[mid];

  int new_end = mid-1;
  int new_start = mid+1;

  if(start <= new_end)
    {
      locRoot->left = new node();
      locRoot->left->right = NULL;
      locRoot->left->left = NULL;
      recurse(arr, locRoot->left, start, new_end);
    }
  if(new_start <= end)
    {
      locRoot->right = new node();
      locRoot->right->right = NULL;
      locRoot->right->left = NULL;
      recurse(arr, locRoot->right, new_start, end);  
    }
}

//helper function to test if tree is balanced
bool balanced(node *locRoot)  
{
  int height(node*);

  if(locRoot == NULL)
    return true;
  
  int left = height(locRoot->left);
  int right = height(locRoot->right);

  if(left-right > 1 || left-right < -1)      
    return false;

    
  bool l = balanced(locRoot->left);
  bool r = balanced(locRoot->right);

  return l && r;
  
}

//main algorithm for a normal tree to compare
void rec2(node *locRoot, int data)
{
  if(locRoot->left == NULL && data < locRoot->data)
    {
      locRoot->left = new node();
      locRoot->left->data = data;
      locRoot->left->left = NULL;
      locRoot->left->right = NULL;
    }

  else if(locRoot->left != NULL && data < locRoot->data)
    rec2(locRoot->left, data);

  else if(locRoot->right == NULL && data > locRoot->data)
    {
      locRoot->right = new node();
      locRoot->right->data = data;
      locRoot->right->right = NULL;
      locRoot->right->left = NULL;
    }
  else
    rec2(locRoot->right, data);
    
  return;
}

//wrapper for a normal tree, I started from index 0
void normal(std::vector<int> arr)
{
  
  srand(time(NULL));

  int r = rand() % arr.size();
  
  root->data = arr[r];
  root->left = NULL;
  root->right = NULL;
  arr.erase(arr.begin()+r);
      
  while(!arr.empty())
    {
      r = rand() % arr.size();
      rec2(root, arr[r]);
      arr.erase(arr.begin()+r);
           
    }
}

//height of the tree
int height(node *locRoot)
{
  if (locRoot == NULL)
    return 0;

  
  int left = height(locRoot->left) + 1;
  int right = height(locRoot->right) + 1;

  if(left > right)
    return left;

  return right;
  
}

//parses the data from file and cleans it. This also calls either the normal tree or binary insertion algorithm
void treemaker()
{
  int node_count(node*);
    
  void normal(std::vector<int>);
  using namespace std;
  
  FILE *fp = fopen("gen.txt", "r");
  if(fp == NULL)
    cout << "Couldn't open" << endl;
  
  set<int> unique;

  int temp;
     
  while(!feof(fp))
    {
      fscanf(fp, "%d", &temp);
      unique.insert(temp);
    }  
  
  fclose(fp);
  set<int>::iterator gogo = unique.begin();
  vector<int> clean;

  for(int i = 0; i < (int) unique.size(); i++)
    {
      clean.push_back(*gogo);
      gogo++;
    }
  
  
  normal(clean);
  //std::cout << "balance boolean: " <<balanced(root) << std::endl;
  std::cout << "tree height: " << height(root) << std::endl;  
  //std::cout <<"total nodes: " << node_count(root) << std::endl;
  
  // std::cout<<std::endl;
  //std::cout<<std::endl;
  
  //recurse(clean, root, 0, clean.size()-1);

  //std::cout << "balance boolean: " <<balanced(root) << std::endl;
  //std::cout << "tree height: " << height(root) << std::endl;  
  //std::cout <<"total nodes: " << node_count(root) << std::endl;
  
}

//helper function that prints in inorder traversal
void print_in_order(node *locRoot)
{
  if(locRoot == NULL)
    return;

  print_in_order(locRoot->left);
  std::cout << locRoot->data << std::endl;
  print_in_order(locRoot->right);
  
}

//as the name suggests
int node_count(node *locRoot)
{
  if(locRoot == NULL)
    return 0;

  int left = node_count(locRoot->left);
  int right = node_count(locRoot->right);

  return left+right+1;
  
}

int main(int argc, char **argv)
{
  root =  new node();
  root->left = NULL;
  root->right = NULL;
  treemaker();
  sleep(1);

  //std::cout << root->left->data << std::endl;
  //std::cout << root->right->data << std::endl;

  return 0;
}
