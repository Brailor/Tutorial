
<form action="sell.php" method="post">
    <select name = "value"> 
      <option>SELECT</option>
        <?php foreach($positions as $position): ?>
             <option value = <?= $position["symbol"] ?> > <?= $position["symbol"] ?></option> 
        <?php endforeach ?>
    </select>
         <button class="btn btn-default" type="submit">
             <span aria-hidden="true" class="glyphicon"></span>
                 Sell
        </button>
</form>    