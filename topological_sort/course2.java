package topological_sort;

public import java.util.*;

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer>[] graph = new List[numCourses];
        Arrays.setAll(graph, x -> new ArrayList<>());

        int[] inDegree = new int[numCourses];

        for (int[] prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            graph[prerequisiteCourse].add(course);
            ++inDegree[course];
        }

        Deque<Integer> queue = new ArrayDeque<>();

        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }

        int[] order = new int[numCourses];
        int courseCount = 0;

        while (!queue.isEmpty()) {
            int currentCourse = queue.poll();
            order[courseCount++] = currentCourse;

            for (int adjacentCourse : graph[currentCourse]) {
                if (--inDegree[adjacentCourse] == 0) {
                    queue.offer(adjacentCourse);
                }
            }
        }

        return courseCount == numCourses ? order : new int[0];
    }
}
 {
    
}
