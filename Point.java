import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Point {


   static void DFS (List < List<Integer>> adj , boolean[] visited , int point , int curr)
    {

        visited[curr] = true;

        for(int i : adj.get(curr))
        {
            if( i != point)
            {
                if(!visited[i])
                {
                    DFS(adj, visited, point, i);
                }
            }
        }

    }


   static void articulation(List<List<Integer>> adj , int v)
   {


        
        for(int i = 1 ; i  <= v ; i++)
        {   
            boolean[] visited = new boolean[v+1];
           

            int com = 0;
            for(int j = 1 ; j <= v ; j++)
            {
                if( j != i)
                {
                    if(!visited[j])
                    {
                        com++;
                        DFS(adj, visited, i, j);

                    }
                }
            }
            
            if(com > 1)
            {
                System.out.println(i);
            }

        }
         
   }


   static void addEdge(List<List<Integer>> adj , int u, int v) {
        adj.get(u).add(v);
        adj.get(u).add(u);
    }

    // Driver Code
    public static void main(String[] args) {
        // Create graphs given in above diagrams
        System.out.println("Articulation points in the graph ");
        int V = 5;
        List<List<Integer>> adj1 = new ArrayList<>();
        for (int i = 0; i <= V; i++) {
            adj1.add(new ArrayList<>());
        }
        addEdge(adj1, 1, 2);
        addEdge(adj1, 2, 3);
        addEdge(adj1, 1, 3);
        addEdge(adj1, 3, 4);
        addEdge(adj1, 4, 5);
        articulation(adj1, V);
    }
    
}
