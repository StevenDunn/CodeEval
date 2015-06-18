# juggling with zeros solution in perl for code eval by steven a dunn

use 5.014;
use strict;

my $file = $ARGV[0];
open(INFILE, "<$file") or die("Cannot open file $file for reading: $!");

while(my $line = <INFILE>) {
    # skip blank lines
    next if($line =~ m/^s$/);
    chomp($line);

    my @tokens = split(/ /, $line);
    my $binary;
    for (my $count = 0; $count < scalar(@tokens); $count += 2) {
        my $flag = @tokens[$count];
        my $seq = @tokens[$count+1];
        if ($flag eq "00") {
            $binary .= &ones($seq);
        }
        else {
            $binary .= $seq;
        }
    }
    # weird hack I found on Stack Overflow
    $binary = oct("0b".$binary);

    print "$binary \n";
}
close(INFILE);

sub ones {
    my $len = length(@_[0]);
    my $ones_seq;
    while(length($ones_seq) < $len) {
        $ones_seq .= "1";
    }
    $ones_seq;
}