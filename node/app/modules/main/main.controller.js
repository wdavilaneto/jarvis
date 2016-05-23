
(function () {

    'use strict';

    angular.module('jarvisApp.main').controller('MainController', MainController);

    MainController.$inject = ['$scope', '$stateParams', '$modal', '$location', 'jsog', 'neuralNetService' ];

    function MainController($scope, $stateParams , $modal, $location, jsog, neuralNetService ) {

        var vm = this;

        vm.gridOptions = neuralNetService.createGridOptions( true);
        vm.pagination = vm.gridOptions.getPagination(); // just for ease use/access
        vm.resultPage = {}; // Paged result for search filter

        // Search de todos os elementos inicial ( quando entra na tela )
        neuralNetService.findAll( vm.pagination.getPageRequest() , function (data) {
            vm.resultPage = data;
            vm.resultPage.content = jsog.decode(data.content);
        });
    }

})();
