
// Assignment 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <random>

using namespace std;

int main(int argc, char* argv[])
{

	//if the user didn't provide 2 arguments, let the user know how to do it and end program
    if(argc != 2)
    {
    	cout << "Usage: " << argv[0] << " filename.txt" << endl;
    	return 1;
    }

  // always one argument for the filename
	char* filename = argv[1];
  // for user to be able to run another file
	char choice;
	do {

		//if the file can't be opened let the user know & end
		cout << "Opening file: " << filename << endl;
		ifstream infile(filename);
		if(infile.is_open() == false)
    {
			cout << "File not found!" << endl;
			return 2;
		}

    // output file
		ofstream outfile("karolina.out");

		//variables to track what's in this line of DNA
		int A = 0;
		int C = 0;
		int G = 0;
		int T = 0;
		int AA = 0;
		int AC = 0;
		int AG = 0;
		int AT = 0;
		int CA = 0;
		int CC = 0;
		int CG = 0;
		int CT = 0;
		int GA = 0;
		int GC = 0;
		int GG = 0;
		int GT = 0;
		int TA = 0;
		int TC = 0;
		int TG = 0;
		int TT = 0;
		int valid_line_count = 0;
		int total_nucleotide_count = 0;
		int bigram_count = 0;
		double variance = 0.0;


		//prepare to read each line in the file...
		string nextline;

		while( infile >> nextline ) //read a line
    {
			cout << nextline << endl; //(output it to the screen)

			//clean up the data in the file
			string valid_dna = "";

			// go through each nucleotide capitalizing and keeping only ACGT
			for(int i=0;i<nextline.length();i++)
      {
				//pull next nucleotide out of the string
				char nextnucleotide = nextline[i];
				//capitalize if it's lowercase
				if( nextnucleotide >= 'a' && nextnucleotide <= 'z' )
        {
					//convert from lowercase to uppercase
					nextnucleotide = nextnucleotide - 'a' + 'A';
			  }

				//keep only ACGT in the file
				if( nextnucleotide == 'A' || nextnucleotide == 'C' || nextnucleotide == 'G' || nextnucleotide == 'T' )
        {
					valid_dna = valid_dna + nextnucleotide;
				}

			}


			//show the cleaned up data
			cout << "Cleaned up: " << valid_dna << endl;
			if(valid_dna.length() == 0) //if there's nothing valid on this line of the file
      {
				continue; //go back to the top and get the next line
			}

			valid_line_count++; // one valid line of DNA in the file
			total_nucleotide_count = total_nucleotide_count + valid_dna.length();

			//process the cleaned data
			for(int i=0;i<valid_dna.length();i++)
      {
				char nextnucleotide = valid_dna[i];
				// if there's a following nucleotide pull it as well
				char followingnucleotide = ' ';
				if(i+1 < valid_dna.length() )
        {
					followingnucleotide = valid_dna[i+1];
				}

				if(nextnucleotide == 'A')
        {
					A++;
					if(followingnucleotide == 'A')
          {
						AA++;
						bigram_count++;
				  }
					else if(followingnucleotide == 'C')
          {
						AC++;
						bigram_count++;
					}
					else if(followingnucleotide == 'G')
          {
						AG++;
						bigram_count++;
					}
					else if(followingnucleotide == 'T')
          {
						AT++;
						bigram_count++;
					}
				}
				else if(nextnucleotide == 'C')
        {
					C++;
					if(followingnucleotide == 'A')
          {
						CA++;
						bigram_count++;
					}
					else if(followingnucleotide == 'C')
          {
						CC++;
						bigram_count++;
					}
					else if(followingnucleotide == 'G')
          {
						CG++;
						bigram_count++;
					}
					else if(followingnucleotide == 'T')
          {
						CT++;
						bigram_count++;
					}
				}
				else if(nextnucleotide == 'G')
        {
					G++;
					if(followingnucleotide == 'A')
          {
						GA++;
						bigram_count++;
					}
					else if(followingnucleotide == 'C')
          {
						GC++;
						bigram_count++;
					}
					else if(followingnucleotide == 'G')
          {
						GG++;
						bigram_count++;
					}
					else if(followingnucleotide == 'T')
          {
						GT++;
						bigram_count++;
					}
				}
				else if(nextnucleotide == 'T')
        {
					T++;
					if(followingnucleotide == 'A')
          {
						TA++;
						bigram_count++;
					}
					else if(followingnucleotide == 'C')
          {
						TC++;
						bigram_count++;
					}
					else if(followingnucleotide == 'G')
          {
						TG++;
						bigram_count++;
					}
					else if(followingnucleotide == 'T')
          {
						TT++;
						bigram_count++;
					}
				}
			} //end of for loop that processes each nucleotide
			cout << "Stats: "
				 << A << " " << C << " " << G << " " << T << " / "
				 << AA << " " << AC << " " << AG << " " << AT << " / "
				 << CA << " " << CC << " " << CG << " " << CT << " / "
				 << GA << " " << GC << " " << GG << " " << GT << " / "
				 << TA << " " << TC << " " << TG << " " << TT << " / "
				 << endl;
		} //end of while loop that processes every line in the file

		//mean calculation
		double mean = total_nucleotide_count*1.0/valid_line_count;

		// variance calculation
    //if there is only 1 line there is no variance or standard deviation
		if(valid_line_count == 1)
    {
			variance = 0.0;
		}
    // rewind the file to calculate variance
		else
    {
			infile.clear();
			infile.seekg(0);
			while( infile >> nextline )
      {
				double diff = nextline.length() - mean;
				double diff_sqr = diff*diff;
				double calculated = diff_sqr/(valid_line_count-1);
				variance = variance + calculated;
			}
		}

		//standard deviation calculation
		double standard_deviation = sqrt(variance);

		//output file header
		outfile << "Assignment 1" << endl;
		outfile << "Karolina Michalewska" << endl;
		outfile << "Student ID: 2298813" << endl;
		outfile << "CPSC 350" << endl;

		outfile << " * Basic Statistics * " << endl;

		outfile << "SUM: " << total_nucleotide_count << endl;
		outfile << "MEAN: " << mean << endl;
		outfile << "Variance: " << variance << endl;
		outfile << "Standard Deviation: " << standard_deviation << endl;

		//Relative probability of nucleotides
		outfile << " * Relative Probability of Nucleotides* " << endl;

		outfile << "A: " << A << " out of " << total_nucleotide_count << ": " << A*100.0/total_nucleotide_count << "%" << endl;
		outfile << "C: " << C << " out of " << total_nucleotide_count << ": " << C*100.0/total_nucleotide_count << "%" << endl;
		outfile << "G: " << G << " out of " << total_nucleotide_count << ": " << G*100.0/total_nucleotide_count << "%" << endl;
		outfile << "T: " << T << " out of " << total_nucleotide_count << ": " << T*100.0/total_nucleotide_count << "%" << endl;

		//Relative bigram probability
		outfile << " *Relative Probability of Bigrams* " << endl;

		outfile << "AA: " << AA << " out of " << bigram_count << ": " << AA*100.0/bigram_count << "%" << endl;
		outfile << "AC: " << AC << " out of " << bigram_count << ": " << AC*100.0/bigram_count << "%" << endl;
		outfile << "AG: " << AG << " out of " << bigram_count << ": " << AG*100.0/bigram_count << "%" << endl;
		outfile << "AT: " << AT << " out of " << bigram_count << ": " << AT*100.0/bigram_count << "%" << endl;
		outfile << "CA: " << CA << " out of " << bigram_count << ": " << CA*100.0/bigram_count << "%" << endl;
		outfile << "CC: " << CC << " out of " << bigram_count << ": " << CC*100.0/bigram_count << "%" << endl;
		outfile << "CG: " << CG << " out of " << bigram_count << ": " << CG*100.0/bigram_count << "%" << endl;
		outfile << "CT: " << CT << " out of " << bigram_count << ": " << CT*100.0/bigram_count << "%" << endl;
		outfile << "GA: " << GA << " out of " << bigram_count << ": " << GA*100.0/bigram_count << "%" << endl;
		outfile << "GC: " << GC << " out of " << bigram_count << ": " << GC*100.0/bigram_count << "%" << endl;
		outfile << "GG: " << GG << " out of " << bigram_count << ": " << GG*100.0/bigram_count << "%" << endl;
		outfile << "GT: " << GT << " out of " << bigram_count << ": " << GT*100.0/bigram_count << "%" << endl;
		outfile << "TA: " << TA << " out of " << bigram_count << ": " << TA*100.0/bigram_count << "%" << endl;
		outfile << "TC: " << TC << " out of " << bigram_count << ": " << TC*100.0/bigram_count << "%" << endl;
		outfile << "TG: " << TG << " out of " << bigram_count << ": " << TG*100.0/bigram_count << "%" << endl;
		outfile << "TT: " << TT << " out of " << bigram_count << ": " << TT*100.0/bigram_count << "%" << endl;

    // 1000 Gaussian distribution strings
		for(int i=0;i<1000;i++)
    {
      // random numbers between 0 and 1
			double a = (double)rand() / ((double)RAND_MAX + 1);
			double b = (double)rand() / ((double)RAND_MAX + 1);
			double PI = 3.1415926535;
			double C = sqrt(-2 * log(a)) * cos(2*PI*b);
			double val = standard_deviation * C + mean;
      //create a string with lenght of len
			int len = (int)val;
			string strand = " ";

      // creating the strings
			double pick;

			pick = (double)rand() / ((double)RAND_MAX + 1);
			if(pick < A)
      {
				strand += "A";
			}
			else if(pick < A + C)
      {
				strand += "C";
			}
			else if(pick < A + C + G)
      {
				strand += "G";
			}
			else
      {
				strand += "T";
			}

			for(int i=1;i<len;i++)
      {
				pick = (double)rand() / ((double)RAND_MAX + 1);
				if(pick < A*1.0/total_nucleotide_count)
        {
					strand += "A";
				}
				else if(pick < A*1.0/total_nucleotide_count + C*1.0/total_nucleotide_count)
        {
					strand += "C";
				}
				else if(pick < A*1.0/total_nucleotide_count + C*1.0/total_nucleotide_count + G*1.0/total_nucleotide_count)
        {
					strand += "G";
				}
				else
        {
					strand += "T";
				}
			}

			outfile << strand << endl;

		}

    // close the output file
		outfile.close();

		// ask user to process another file
		cout << "Do you want to process another file?  y/n" << endl;
		cin >> choice;
		while(choice != 'y' && choice != 'n')
    {
			cout << "Invalid input. Try again: " << endl;
			cin >> choice;
		}
		if(choice == 'y')
    {
			cout << "Enter the file name: " << endl;
			scanf("%s", filename);
		}


  // do all of that when the choice is y
	} while(choice == 'y');

	return 0;

}
