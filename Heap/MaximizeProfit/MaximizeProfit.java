import java.util.*;

class MaxKProfit {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int b = sc.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();

        long res = maxKProfit(n, b, a);

        System.out.println(res);
    }

    static long maxKProfit(int k, int n, int[] seats) {
           // in a priority queue
    PriorityQueue<Long> pq;
    pq = new PriorityQueue<>(Collections.reverseOrder());
     
    for(int i = 0; i < k; i++)
       pq.add((long)seats[i]);
 
    // To store the maximized profit
    long profit = 0;
 
    // To count the people that
    // have been sold a ticket
    long c = 0;
    while (c < n)
    {
 
        // Get the maximum number of
        // vacant seats for any row
        long top = pq.remove();
 
        // If there are no vacant seats
        if (top == 0)
            break;
 
        // Update the profit
        profit = profit + top;
 
        // Push the updated status of the
        // vacant seats in the current row
        pq.add(top - 1);
 
        // Update the count of persons
        c++;
    }
     
    return profit;
    }
}