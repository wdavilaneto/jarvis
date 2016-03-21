
(function() {
	'use strict';

    /**
     *  Guick Generate class: https://github.com/wdavilaneto/guick
     *  Author: service-wdavilaneto@redhat.com
     *  This source is free under The Apache Software License, Version 2.0
     *  license url http://www.apache.org/licenses/LICENSE-2.0.txt
     *
     * @ngdoc function
     * @name jarvisApp.controller:neuralNetController
     * @description
     * # neuralNetController
     * Controller of the jarvisApp
     */
    angular.module('jarvisApp').controller('neuralNetChildController', neuralNetChildController);

    neuralNetChildController.$inject = ['$scope', '$stateParams', '$modal', '$location', 'jsog', 'neuralNetService' ];

    function neuralNetChildController($scope, $stateParams , $modal, $location, jsog, neuralNetService  ) {

        var vm = this;

        $scope.gridOptions = neuralNetService.createGridOptions( true );
        $scope.pagination = $scope.gridOptions.getPagination(); // just for ease use/access
        $scope.resultPage = {}; // Paged result for search filter

        $scope.findneuralNet();
    }

})();
