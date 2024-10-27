import java.util.*;

public class strongly_connected_components {

    public static List<List<Integer>> getTranspose(List<List<Integer>> adj , int n)
    {
        //initializing list
        List<List<Integer>> reverseGraph = new ArrayList<>();
        for (int i = 0 ; i < n ; i++)
        {
            reverseGraph.add(new ArrayList<>());
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j : adj.get(i))
            {
                reverseGraph.get(j).add(i);
            }
        }

        return reverseGraph;

    }

    public static void DFS ( List<List<Integer>> graph , int v , boolean[] visited , List<Integer> components)

    {
        visited[v] = true;

        for(int i : graph.get(v))
        {
            if(!visited[i])
            {
                DFS(graph , i , visited , components);
            }
           
        }

        components.add(v);
    }


    public static List<Integer> fillOrder(List<List<Integer>> graph , int n  , boolean[] visited )
    {
        List<Integer> order = new ArrayList<>();
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
            {
                DFS(graph , i , visited , order );
            }
        }

        return order;
    }

    public static void Kosaraju(List<List<Integer>> graph , int N)
    {
        boolean[] visited = new boolean[N];

        List<Integer> order = fillOrder(graph, N, visited);

        List<List<Integer>> reverseGraph = getTranspose(graph, N);

        Collections.reverse(order);
        visited = new boolean[N];

        List<List<Integer>> SCC = new ArrayList<>();
        for(int i = 0 ; i < order.size() ; i++)
        {
            int v = order.get(i);

            if(!visited[v])
            {
                List<Integer> comp = new ArrayList<>();
                DFS(reverseGraph , v , visited , comp);
                SCC.add(comp);

            }

            
        }

        System.out.println("number of strongly connected components: " + SCC.size());

        for(List <Integer> value : SCC )
        {
            System.out.println(value);
        } 

        


    }

        public static void main(String[] args) {
            

            Scanner scanner = new Scanner(System.in);
            int t = scanner.nextInt();

            
            for(int i = 0; i < t ; i++)
            {
                List<List<Integer>> adj = new ArrayList<>();

                int n = scanner.nextInt();
                int m = scanner.nextInt();
            
            for (int j = 0; j < n; j++) {
                adj.add(new ArrayList<Integer>());
            }

            for(int j = 0 ; j < m ; j++ )
            {
                int a = scanner.nextInt();
                int b = scanner.nextInt();
                adj.get(a).add(b);
            }
            
        

            Kosaraju(adj , n);

            }
        
            
            
        }
    
}
