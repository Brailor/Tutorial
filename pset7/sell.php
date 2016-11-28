<?php

    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "GET"){
        
      
        $rows = CS50::query("SELECT symbol, shares FROM portfolio WHERE user_id = ?", $_SESSION["id"]);
        
        $positions = [];
    
    foreach($rows as $row){
        
        $stock = lookup($row["symbol"]);
        if($stock != false){
            
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "symbol" => $row["symbol"],
                "shares" => $row["shares"]
               ];
        }
     
    }
     render("selling.php", ["title" => "Sell", "positions" => $positions]);
}
    else if($_SERVER["REQUEST_METHOD"] == "POST"){
       
        
        if(!($_POST["value"] == "SELECT")){
           
            
            $data = lookup($_POST["value"]);
            $adatok = CS50::query("SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["value"]);
            $cash = $data["price"] * $adatok[0]["shares"];
            $sell = CS50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol = ?",$_SESSION["id"], $_POST["value"]);
            if($sell !== 0){
                $update = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $cash, $_SESSION["id"]);
                $history = CS50::query("INSERT INTO history(user_id, action, date, price, shares, symbol) VALUES
                (?,'SELL', NOW(), ?, ?, ?)", $_SESSION["id"], $data["price"], $adatok[0]["shares"], $data["symbol"]);
                redirect("index.php");
               
            }
        }
        else if($_POST["value"] == "SELECT"){ 
            error("You must select a stock to sell!", "sell.php", "sell.php");
        }
    
    
    
}
  

















?>