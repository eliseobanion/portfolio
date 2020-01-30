public class TowersofHanoi
{
        private int totalDisks;

        public TowersofHanoi(int disks)
        {
                totalDisks = disks;
        }//TowersofHanoi Constructor

        public void solve()
        {
                moveTower(totalDisks, 1, 3, 2);
        }//solve

        public void moveTower(int numDisks, int start, int end, int temp)
        {
                if (numDisks == 1)
                        moveOneDisk(start, end);
                else
                {
                        moveTower(numDisks - 1, start, temp, end);
                        moveOneDisk(start, end);
                        moveTower(numDisks -1, temp, end, start);
                }//else
        }//moveTower

        private void moveOneDisk(int start, int end)
        {
                System.out.println("Move one disk from " + start + " to " + end);
        }//moveOneDisk
}//TowersofHanoi
