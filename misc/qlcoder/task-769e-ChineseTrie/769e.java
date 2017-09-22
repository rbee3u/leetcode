import java.util.Random;

public class Main
{
	 public static void main(String[] args)
	    {
	    	int a=0x4e00;
	    	int b=0x9fa5;
	    	Random r=new Random(10);
	    	for(int i=0;i<50000000;i++)
	    	{
	    		int j=(int)(r.nextInt(4))+2;
	    		String s="";
	    		for(int jj=0;jj<j;jj++)
	    		{
	    			s+=(char)(a+(int)(r.nextInt(b-a)));
	    		}
	    		System.out.println(s);
	    	}

}
