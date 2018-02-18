#include <bits/stdc++.h>
using namespace std;
int height=0;
struct Node{
    int data;
    Node* left;
    Node* right;
    int depth;
};
Node* createNode(int val,int d)
{
    Node* n = new Node;
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    n->depth=d;
    return n;
}
int insertNode(Node* root, int val)
{
    if(root->data == val)
        return -1;
    if(root->data < val)
    {
        if(root->right != NULL)
        {
            root->depth = max(root->depth,1+insertNode(root->right,val));
            return root->depth;
        }
        else
        {
            Node* newnode = createNode(val,0);
            if(root->depth==0)
                root->depth++;
            root->right = newnode;
            return root->depth;
        }
    }
    else
    {
        if(root->left != NULL)
        {
            root->depth = max(root->depth,1+insertNode(root->left,val));
            return root->depth;
        }
        else
        {
            Node* newnode = createNode(val,0);
            if(root->depth==0)
                root->depth++;
            root->left = newnode;
            return root->depth;
        }
    }
    return root->depth;
}
void dfs(Node* root)
{
    height += root->depth;
    cout << root->data << " " << root->depth << endl;
    if(root->left != NULL)
        dfs(root->left);
    if(root->right != NULL)
        dfs(root->right);
}
vector<string> split_string(string);


/*
 * Complete the function below.
 */
vector<int> heightAndTotalHeight(vector<int> arr) {
    // Write your code here.
    int n = arr.size();
    Node* root =createNode(arr[0],0);
    for(int i=1; i<n; i++)
        insertNode(root,arr[i]);
    dfs(root);
    vector<int> ans;
    ans.push_back(root->depth);
    ans.push_back(height);
    return ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_size;
    cin >> arr_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_str_temp;
    getline(cin, arr_str_temp);

    vector<string> arr_str = split_string(arr_str_temp);

    vector<int> arr(arr_size);
    for (int arr_i = 0; arr_i < arr_size; arr_i++) {
        int arr_item = stoi(arr_str[arr_i]);

        arr[arr_i] = arr_item;
    }

    vector<int> result = heightAndTotalHeight(arr);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
