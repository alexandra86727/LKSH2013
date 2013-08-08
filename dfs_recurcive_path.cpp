#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

const int NA = -1;
int n, c, b, a[110][110], use[110], d[110], x, y, v;
int path[3000][300];

void dfs(int u) {
    use[u] = 1;
    cout << "u: " << u + 1 << " ";
    if (d[u] == NA)
    {
        d[u] = 0;
        path[u][ ++path[u][0] ] = u;
    }
    
    for (int v = 0; v < n; v++)
        if (a[u][v])
            if (!use[v]) {
                for (int j = 1; j < path[u][0]+1; j++)
                {
                    path[v][ ++path[v][0] ] = path[u][j];
                }
                path[v][ ++path[v][0] ] = v;
                d[v] = d[u] + 1;
                dfs(v);
            }
}

int main()
{
   freopen("input.txt", "r", stdin);
   cin >> n >> c >> b >> v;
   for (int i = 0; i < n; i++) {
       cin >> x >> y;
       a[x - 1][y - 1] = 1;
   }
    for(int i = 0; i < n; i++) {
        d[i] = NA;
        path[i][0] = 0;
        for (int j = 1; j < n; j++)
            path[i][j] = NA;
    }
    dfs(c - 1);
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            if(j == 0)
                cout << setw(3) << path[i][j] << "  ";
            else
                if(path[i][j] == NA)
                    cout << setw(3) << path[i][j] << "  ";
                else
                    cout << setw(3) << path[i][j] + 1 << "  ";
        }
            
        cout << endl;
    }
    cout << endl;
   for (int i = 0; i < n; i++)
       cout << d[i] << " ";  
   return 0;
}
