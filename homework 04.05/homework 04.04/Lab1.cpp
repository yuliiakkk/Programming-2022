#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int N = 10;
vector<vector<int>> graph;//масив суміжних аершин до  і вершин
bool isVisited[N];//для зберігання вершин які вже були відвідані

bool DFS(int startNode, int destinationNode)
{
    stack<int>nodes;
    nodes.push(startNode);
    isVisited[startNode - 1] = true;

    while (!nodes.empty())
    {
        int curr = nodes.top();
        nodes.pop();

        if (destinationNode == curr)
            return true;


        for (int i = 0; i < graph[curr - 1].size(); i++)
        {
            int neighbour = graph[curr - 1][i];
            if (!isVisited[neighbour - 1])
            {
                isVisited[neighbour - 1] = true;
                nodes.push(neighbour);
            }
        }
    }

    return false;
}


int main()
{

    for (int i = 0; i < N; i++)
    {
        graph.push_back(vector<int>());
    }
   
    int i, j;
  
    do
    {
        cin >> i >> j;
        if ((i == 0 && j == 0))
        {
            break;
        }
        graph[i - 1].push_back(j);
        graph[j - 1].push_back(i);
    } 
    while (true);

    int start, end;
    cout << "Enter start and end:" << endl;
    cin >> start >> end;
   

    if (DFS(start,end))
    {
        cout << "A path exists between " << start << " and " << end << endl;
    }
    else 
    {
        cout << "No path exists between " << start << " and " << end << endl;
    }

    for (int i = 0; i < N; i++)
    {
        if (isVisited[i])
            cout << i + 1 << " ";
    }

    return 0;
}


