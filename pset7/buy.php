<?php

    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "GET"){
        render("buying.php", ["title" => "Buy"]);
    }
    else if($_SERVER["REQUEST_METHOD"] == "POST"){
        if(empty($_POST["symbol_value"]) || empty($_POST["share_value"])){
            
            error("Share and/or Symbol field is empty!", "buy.php");
        
        }
        else{
             if(preg_match("/^\d+$/", $_POST["share_value"]) == false){
                apologize("You can't buy negative or non-whole number amount of shares!", "buy.php");
            }
            else if(empty($stock = lookup($_POST["symbol_value"]))){
                error("Company does not exist!", "buy.php");
            }
      //forces symbols to uppercase    
      strtoupper($stock["symbol"]);
  
      $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
     
      $sharePrice = $stock["price"] * $_POST["share_value"];
      
      //check if you have enough money for that stock
     if($cash[0]["cash"] < $sharePrice){
         apologize("You don't have enough money for that!", "buy.php");
     }
     
     //buying the stock and update the cash
     else{
         
      $buying = CS50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES(?, ?, ?)
      ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",
      $_SESSION["id"], $stock["symbol"], $_POST["share_value"]);
      
      $cashUpdate = CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $sharePrice, $_SESSION["id"]);
      
      $history = CS50::query("INSERT INTO history(user_id, action, date, price, shares, symbol) VALUES (?,'BUY', NOW(), ?, ?, ?)", 
      $_SESSION["id"], $stock["price"], $_POST["share_value"], $stock["symbol"]);
     }
     
      if(($cashUpdate  == 0 ) || ($buying  == 0)){
          error("Something went wrong! :/", "buy.php");
      }
      else{
      redirect("index.php");

        }  
    }
}
?>