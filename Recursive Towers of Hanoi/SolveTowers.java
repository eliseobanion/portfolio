public class SolveTowers
{
        public static long recursivePower(long x, long y)
        //PRE: y > 0
        //POS: none
        //TAS: This method is the solution to Exercise 7.2 which returns x^y
        {
                //if (y == 1)
                //	return x;
                //else
                //	return x * recursivePower(x, --y);
                //8.2

                //if (y == 1)
                //	return x;
                //else
                //	return x + recursivePower(x, --y);
                //8.3

                if (x < 2)
                        return 1;
                else
                    	return recursivePower(x - 1, y) + recursivePower(x - 2, y);

                //if (x == 1)
                //	return 1;
                //else
                //return x * recursivePower(--x, y);
                //8.6
        }//recursivePower

        public static void main (String[] args)
        {
                //TowersofHanoi towers = new TowersofHanoi(4);
                //towers.solve();
                print ("The fib 5 is: " + recursivePower(5,7));
        }//main

        public static void print (String s)
        //TAS: To save keystrokes when typing System.out
        {
                System.out.println(s);
        }//print
}//SolveTowers
