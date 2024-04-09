<!DOCTYPE html>
<html>
<head>
	<title>Dropdown list example</title>
</head>
<body>
	<form method="post">
		<?php
		// Define the list of cities
		$cities = array(
		    'CA' => array('Los Angeles', 'San Francisco', 'San Diego'),
		    'NY' => array('New York City', 'Buffalo', 'Rochester'),
		    'TX' => array('Houston', 'Dallas', 'Austin')
		);

		// Define the list of countries
		$countries = array(
		    'USA' => 'United States',
		    'Canada' => 'Canada',
		    'UK' => 'United Kingdom'
		);

		// Define the list of states
		$states = array(
		    'CA' => 'California',
		    'NY' => 'New York',
		    'TX' => 'Texas'
		);

		// Define the default values
		$selected_country = 'USA';
		$selected_state = 'CA';
		$selected_city = '';

		// Handle form submissions
		if ($_SERVER['REQUEST_METHOD'] === 'POST') {
		    $selected_country = isset($_POST['country']) ? $_POST['country'] : '';
		    $selected_state = isset($_POST['state']) ? $_POST['state'] : '';
		    $selected_city = isset($_POST['city']) ? $_POST['city'] : '';
		}

		// Create first drop-down list for countries
		echo '<label for="country">Country:</label>';
		echo '<select id="country" name="country">';
		foreach ($countries as $code => $name) {
		    $selected = ($selected_country === $code) ? 'selected' : '';
		    echo "<option value=\"$code\" $selected>$name</option>";
		}
		echo '</select>';

		// Create second drop-down list for states
		echo '<label for="state">State:</label>';
		echo '<select id="state" name="state">';
		foreach ($states as $code => $name) {
		    $selected = ($selected_state === $code) ? 'selected' : '';
		    echo "<option value=\"$code\" $selected>$name</option>";
		}
		echo '</select>';

		// Create third drop-down list for cities
		echo '<label for="city">City:</label>';
		echo '<select id="city" name="city">';
		if (array_key_exists($selected_state, $cities)) {
		    foreach ($cities[$selected_state] as $name) {
		        $selected = ($selected_city === $name) ? 'selected' : '';
		        echo "<option value=\"$name\" $selected>$name</option>";
		    }
		}
		echo '</select>';

		// Add submit button
		echo '<br><br>';
		echo '<input type="submit" value="Submit">';
		?>

		<?php
		// Display selected options
		if ($_SERVER['REQUEST_METHOD'] === 'POST') {
		    echo '<br><br>';
		    echo "Selected Country: " . $countries[$selected_country];
		    echo '<br>';
		    echo "Selected State: " . $states[$selected_state];
		    echo '<br>';
		    echo "Selected City: " . $selected_city;
		}
		?>
	</form>
</body>
</html>