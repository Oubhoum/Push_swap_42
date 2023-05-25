<?php
$game = array("paper", "scissors", "rock");
$computer_choice = $game[rand(0, 2)];

echo "Choose rock, paper, or scissors: ";
$choice = readline();

if (!in_array($choice, $game)) {
    echo "please choice the correct \"paper\", \"scissors\", \"rock\"\n";
    exit();
}
if ($choice === $computer_choice) {
    echo "==\n";
    exit();
}
if ($choice === "paper") {
	if ($computer_choice == "rock") {
		echo "Congratulations! You won! The computer chose $computer_choice \n";
	}
	else {
		echo "Sorry, you lost. The computer chose $computer_choice \n";
	}
}
else if ($choice === "scissors") {
	if ($computer_choice == "rock") {
		echo "Sorry, you lost. The computer chose $computer_choice \n";
	}
	else {
		echo "Congratulations! You won! The computer chose $computer_choice \n";
	}
}
else if ($choice === "rock") {
	if ($computer_choice == "scissors") {
		echo "Congratulations! You won! The computer chose $computer_choice \n";
	}
	else {
		echo "Sorry, you lost. The computer chose $computer_choice \n";
	}
}
?>