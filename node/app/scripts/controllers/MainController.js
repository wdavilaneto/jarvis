'use strict';

/**
 * @ngdoc function
 * @name jarvisApp.controller:mainController
 * @description
 * # mainController
 * Controller of the jarvisApp
 */
angular.module('jarvisApp').controller('mainController', function($scope) {
    $scope.pageClass = 'page-home';
});

angular.module('jarvisApp').controller('TabsDemoCtrl', function ($scope, $window) {
    $scope.tabs = [
      { title:'Dynamic Title 1', content:'Dynamic content 1' },
      { title:'Dynamic Title 2', content:'Dynamic content 2', disabled: true }
    ];

    $scope.alertMe = function() {
      setTimeout(function() {
        $window.alert('You\'ve selected the alert tab!');
      });
    };
});

angular.module('jarvisApp').controller('PopoverDemoCtrl', function ($scope) {
  $scope.dynamicPopover = 'Hello, World!';
  $scope.dynamicPopoverTitle = 'Title';
});

angular.module('jarvisApp').controller('ButtonsCtrl', function ($scope) {
  $scope.singleModel = 1;

  $scope.radioModel = 'Middle';

  $scope.checkModel = {
    left: false,
    middle: true,
    right: false
  };
});

angular.module('jarvisApp').controller('DefaultDatepickerController', function ($scope) {
    $scope.today = function() {
        $scope.dt = new Date();
    };
    $scope.today();

    $scope.clear = function () {
        $scope.dt = null;
    };

    // Disable weekend selection
    $scope.disabled = function(date, mode) {
        return ( mode === 'day' && ( date.getDay() === 0 || date.getDay() === 6 ) );
    };

    $scope.toggleMin = function() {
        $scope.minDate = $scope.minDate ? null : new Date();
    };
    $scope.toggleMin();

    $scope.open = function($event) {
    $event.preventDefault();
    $event.stopPropagation();

    $scope.opened = true;
    };

    $scope.dateOptions = {
        formatYear: 'dd/MM/yyyy',
        startingDay: 1
    };

    $scope.formats = ['dd/MM/yyyy','dd-MMMM-yyyy', 'dd.MM.yyyy', 'shortDate'];
    $scope.format = $scope.formats[0];
});
