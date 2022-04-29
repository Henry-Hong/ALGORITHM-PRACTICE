// page.75 참고하면 ez
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
using namespace std;

typedef struct node* nodePointer;
typedef struct node{
  char key;
  int frequency;
  nodePointer left, right;
} node;

struct compare { bool operator()(nodePointer p, nodePointer q) { return p->frequency > q->frequency; } };
typedef priority_queue<nodePointer, vector<nodePointer>, compare> PriorityQueue;

int n;
string str;
string codeword[26]; // for lowercase
string CODEWORD[26]; // for uppercase
nodePointer ROOT = NULL;

void preorder(nodePointer root){
  if(root == NULL) return;
  cout << root->key << ":" << root->frequency << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(nodePointer root){
  if(root == NULL) return;
  inorder(root->left);
  cout << root->key << ":" << root->frequency << " ";
  inorder(root->right);
}

nodePointer makeNewNode(char key, int frequency, nodePointer l, nodePointer r){
  nodePointer newNode = new node();
  newNode->key = key;
  newNode->frequency = frequency;
  newNode->left = l;
  newNode->right = r;
  return newNode;
}

nodePointer makeHuffmanTree(vector<char> &S, vector<int> &F, PriorityQueue &pq){
  // make nodes ready
  for(int i=1; i<=n; i++)
    pq.push(makeNewNode(S[i], F[i], NULL, NULL));

  // make Huffman tree
  for(int i=1; i<n; i++){
    nodePointer a = pq.top(); pq.pop();
    nodePointer b = pq.top(); pq.pop();
    pq.push(makeNewNode('+', a->frequency + b->frequency, a, b));
  }

  return pq.top();
}

void makeCodeword(nodePointer root, string code){
  if(root == NULL) return;

  if(root->left == NULL && root->right == NULL) {
    if(root->key >= 'a') codeword[root->key - 'a'] = code;
    else CODEWORD[root->key - 'A'] = code;
  }
  else {
    makeCodeword(root->left, code + "0");
    makeCodeword(root->right, code + "1");
  }
}

void encode(string str){
  for(int i=0; i<str.size(); i++){
    if(str[i] >= 'a') cout << codeword[str[i] - 'a'];
    else cout << CODEWORD[str[i] - 'A'];
  }
}

void decode(nodePointer root, string code, int idx){
  if(root == NULL) return;
  if(root->left == NULL && root->right == NULL){
    cout << root->key;
    if(idx >= code.length()) return; // unavoidable
    decode(ROOT, code, idx); return;
  }
  decode(code[idx] == '0' ? root->left : root->right, code, idx + 1);
}

int main(){

  // inputs
  cin >> n;
  vector<char> S(n+1);    // String
  vector<int> F(n+1);     // Frequency
  PriorityQueue pq;       // priority queue for making tree

  for(int i=1; i<=n; i++) cin >> S[i];
  for(int i=1; i<=n; i++) cin >> F[i];
  
  // make huffman tree
  ROOT = makeHuffmanTree(S, F, pq);

  // traverse
  preorder(ROOT); cout << "\n";
  inorder(ROOT); cout << "\n";

  // make Huffman Code (makeCodeWord)
  makeCodeword(ROOT, "");

  // encode
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> str;
    encode(str); cout << "\n";
  }

  // decode
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> str;
    decode(ROOT, str, 0); cout << "\n";
  }

  return 0;
}
