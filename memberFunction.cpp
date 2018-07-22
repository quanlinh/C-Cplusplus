class Date {
	int d, m,y;
	public:		
		explicit Date(int dd = 0, int mm = 0, int yy = 0);	// initialize
		Date(const char*);		// date in String representation
		void add_year(int n) {
			y += n;
		}			// add n years
		void add_month(int n) {
			m += n;
		} 			// add n months
		void add_day(int n) {
			d += n;
		} 			// add n days
	
};

int main(){return 0;
	Date today{29,4,2018}; 		// initialize date
	Date july4{"July 4, 1983"};	// date in char at pointer arrays
	Date d3 = Date{15};		// explicit conversion
}
