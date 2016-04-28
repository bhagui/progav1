/*Source Code From Laure Gonnord and Bernard Carré*/

#include "trees.h"

// construction of a tree
Tree cons(int val, Tree left, Tree right) {
  PtNode new = (PtNode)malloc(sizeof(Node));
  new->val=val;
  new->left=left;
  new->right=right;
  return new;
}

// create an empty tree
Tree mkEmptyTree(){
  return NULL;
}

// t is empty?
bool isEmpty (Tree t) {
  return t==NULL;
}

// t is a leaf?
bool isLeaf (Tree t) {
  return (!isEmpty(t) && isEmpty(t->left) && isEmpty(t->right));
}

// add x in a bst wtr its value.
void add(Tree *p_t, int x) {
  if (isEmpty(*p_t)==true)
    {
     *p_t = cons(x,NULL,NULL);
    }
  else
    {
      if (x <= (*p_t)->val)
	{
	  add(&(*p_t)->left,x);
	}
      else
	{
	  add(&(*p_t)->right,x);
	}
    }
}

// build a tree "add"ing values of the file fp
void load_tree(FILE *fp, Tree *p_t) {
  int v;
  fscanf(fp, "%d", &v);
  while (!feof(fp))
    {
      add(p_t,v);
      fscanf(fp, "%d", &v);
    }
}

// print values of t in ascendant order (left-value-right)
void print_lvr (Tree t) {  
  if (!isEmpty(t))
    {
      if (isLeaf(t))
	{
	  printf("%d\t",t->val);
	}
      else
	{
	  print_lvr(t->left);
	  printf("%d\t",t->val);
	  print_lvr(t->right);
	}
    }
}

void print_couple (Tree t) {  
  if (!isEmpty(t))
    {
      if (!isEmpty(t->left))
	{
	  printf("(%d,%d)\t",t->val,t->left->val);
	  print_couple(t->left);
	}
      if (!isEmpty(t->right))
	{
	  printf("(%d,%d)\t",t->val,t->right->val);
	  print_couple(t->right);
	}
    }
}

//Section 1.5
void print_rec_edges(Tree t){
  //TODO
}

//PART II

// pre: !isEmpty(t) & !isLeaf(t)
// recursively prints arcs of the tree <value,left,right> into the file fp:
// "value -> left;" if exist
// "value -> right;" if exist
// to do...
void recursive_dot(Tree t, FILE *fp) {
  //TODO
}


// generate a .dot file for the tree
// limits (no arcs) :
//   isEmpty(t) => "empty" digraph
//   isLeaf(t) => only one node
// general case :
//   calls recursive_dot which prints arcs
void generate_dot (Tree t, FILE *fp) {
  fprintf (fp, "digraph G {\n");
  if (!isEmpty(t)) {
    if (isLeaf(t)) {
      fprintf(fp, "\t%d", t->val);
    } else {
      recursive_dot(t,fp);
    }
  }
  fprintf (fp, "}\n");
}
