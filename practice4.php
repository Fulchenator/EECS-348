<?php
// practice4.php
$size = (int)($_POST['size'] ?? 0);

if ($size < 1) {
  echo "Please enter a number greater than 0. <a href='practice4.html'>Back</a>";
  exit;
}
?>
<!DOCTYPE html>
<html>
<body>
  <h1>Multiplication Table (1 to <?php echo $size; ?>)</h1>

  <table border="1" cellpadding="5">
    <tr>
      <th>x</th>
      <?php
      for ($c = 1; $c <= $size; $c++) {
        echo "<th>$c</th>";
      }
      ?>
    </tr>

    <?php
    for ($r = 1; $r <= $size; $r++) {
      echo "<tr>";
      echo "<th>$r</th>";
      for ($c = 1; $c <= $size; $c++) {
        echo "<td>" . ($r * $c) . "</td>";
      }
      echo "</tr>";
    }
    ?>
  </table>

  <p><a href="practice4.html">Back</a></p>
</body>
</html>