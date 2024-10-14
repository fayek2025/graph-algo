import java.util.List;
import java.util.Stack;
import java.util.ArrayList;
import java.util.Arrays;
public class topological_Sort {

    static void dfs(int v , List<List<Integer>> adj , boolean visited[] , Stack<Integer> stack){
        visited[v] = true;
        for(int i : adj.get(v)){
            if(!visited[i]){
                dfs(i , adj , visited , stack);
            }
        }
        stack.push(v);
    }

    static void topologicalSort(int v , List<List<Integer>> adj)
    {
        boolean[] visited = new boolean[v];
        Stack<Integer> stack = new Stack<>();

        for(int i = 0 ; i < v ; i++)
        {
            if(!visited[i])
            {
                dfs(i , adj , visited ,stack );
            }
        }

        System.out.println("Topological Graph");

        while(!stack.empty())
        {
            System.out.print(stack.pop() + " ");
        }

    }

    public static void main(String[] args) {
        int v = 4;
        List<List<Integer>> edges = new ArrayList<>();
        edges.add(Arrays.asList(0, 1));
        edges.add(Arrays.asList(1, 2));
        edges.add(Arrays.asList(3, 1));
        edges.add(Arrays.asList(3, 2));

        List<List<Integer>> adj = new ArrayList<>();

        for(int i = 0 ; i < v ; i++)
        {
            adj.add(new ArrayList<>());
        }

        for(List<Integer> e : edges)
        {
            adj.get(e.get(0)).add(e.get(1));
        }

        topologicalSort(v , adj);


    }
    
}
