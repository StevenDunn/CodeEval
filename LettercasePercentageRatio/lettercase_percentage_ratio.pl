# lettercase percentage ratio solution in perl for code eval by steven a dunn

use 5.014;
use strict;

my $file = $ARGV[0];
open(INFILE, "<$file") or die("Cannot open file $file for reading: $!");

while(my $line = <INFILE>) {
    # skip blank lines
    next if($line =~ m/^s$/);
    chomp($line);

    my $upper_count = 0;
    my $lower_count = 0;

    my @chars = split(//, $line);
    map { $_ =~ /[A-Z]/ ? $upper_count++ : $lower_count++; } @chars;

    my $total_count = $upper_count + $lower_count;
    my $upper_percent = $upper_count / $total_count * 100;
    my $lower_percent = $lower_count / $total_count * 100;

    my $result = sprintf("lowercase: %.2f uppercase: %.2f \n", $lower_percent, $upper_percent);
    print $result;
}
close(INFILE);